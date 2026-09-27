#include "widget.h"
#include "ui_widget.h"
#include <QProcessEnvironment>
#include <QRegularExpression>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , modelProcess(new QProcess(this)) // 初始化进程
{
    ui->setupUi(this);

    // 设置环境变量
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    modelProcess->setProcessEnvironment(env);

    // 设置 QProcess 的通道模式
    modelProcess->setProcessChannelMode(QProcess::MergedChannels); // 合并标准输出和错误输出

    // 连接按钮点击信号到槽函数
    connect(ui->submitButton, &QPushButton::clicked, this, &Widget::onSubmit);

    // 连接进程的输出信号到槽函数
    connect(modelProcess, &QProcess::readyReadStandardOutput, this, &Widget::onModelOutput);
}

Widget::~Widget()
{
    delete ui;
    modelProcess->close(); // 关闭进程
    delete modelProcess;
}

void Widget::onSubmit()
{
    QString question = ui->inputLineEdit->text();
    if (!question.isEmpty()) {
        // 显示用户输入
        ui->outputTextEdit->append("You: " + question);

        // 启动 ollama 进程
        QString program = "ollama"; // ollama 命令
        QStringList arguments;
        arguments << "run" << "deepseek-r1:1.5b" << question; // 模型名称和用户输入

        modelProcess->start(program, arguments); // 启动进程
        modelProcess->closeWriteChannel(); // 刷新输出缓冲区

        // 判断进程是否启动成功
        if (!modelProcess->waitForStarted()) {
            ui->outputTextEdit->append("Model: Failed to start the model process.");
            qDebug() << "Error:" << modelProcess->errorString(); // 打印错误信息
        } else {
            qDebug() << "Process started successfully."; // 打印成功信息
        }

        // 等待进程完成
        if (!modelProcess->waitForFinished()) {
            ui->outputTextEdit->append("Model: Process failed to finish.");
            qDebug() << "Error:" << modelProcess->errorString(); // 打印错误信息
        }
    }
}



void Widget::onModelOutput() {
    // 读取模型的输出
    QByteArray rawOutput = modelProcess->readAllStandardOutput();
    QString output = QString::fromUtf8(rawOutput).trimmed(); // 转换为 UTF-8 编码，并删除多余空白

    // 过滤 ANSI 转义序列
    output = filterAnsiEscapeSequences(output);

    // 显示模型的回答
    if (!output.isEmpty()) {
        // 获取当前的文本光标
        QTextCursor cursor = ui->outputTextEdit->textCursor();

        // 如果是第一次输出，添加 "Model: "
        if (!ui->outputTextEdit->toPlainText().contains("Model: ")) {
            ui->outputTextEdit->append("Model: "); // 添加 "Model: " 并换行
        }

        // 将光标移动到文档末尾
        cursor.movePosition(QTextCursor::End);

        // 追加输出内容（不换行）
        cursor.insertText(output);

        // 将光标设置回文档末尾
        ui->outputTextEdit->setTextCursor(cursor);

        // 确保光标可见
        ui->outputTextEdit->ensureCursorVisible();
    }

    // 清空输入框
    ui->inputLineEdit->clear();
}

QString Widget::filterAnsiEscapeSequences(QString& input) {
    // 正则表达式匹配 ANSI 转义序列
    static QRegularExpression ansiEscapeRegex(R"(\x1B\[([0-9;]*[mGKH]|[\?][0-9;]*[hl]))");
    QString result = input.replace(ansiEscapeRegex, "");

    qDebug() << "Output after filtering:" << result;
    return result;
}
