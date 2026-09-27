#include <QAPPlication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>//水平布局
#include <QVBoxLayout>//垂直布局
#include <QWidget>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QLabel *infoLable = new QLabel;
	QLabel *openLable = new QLabel;
	QLineEdit *cmdLineEdit = new QLineEdit;
	QPushButton *commitButton = new QPushButton;
	QPushButton *cancelButton = new QPushButton;
	QPushButton *browseButton = new QPushButton;
	
	infoLable->setText("input cmd:");
	openLable->setText("open");
	commitButton->setText("commit");
	cancelButton->setText("cancel");
	browseButton->setText("browse");
	
	QHBoxLayout *cmdLayout = new QHBoxLayout;//水平布局对象
	cmdLayout->addWidget(openLable);
	cmdLayout->addWidget(cmdLineEdit);
	
	QHBoxLayout *buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(commitButton);
	buttonLayout->addWidget(cancelButton);
	buttonLayout->addWidget(browseButton);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;//垂直布局对象
	mainLayout->addWidget(infoLable);
	mainLayout->addLayout(cmdLayout);
	mainLayout->addLayout(buttonLayout);
	
	QWidget w;
	w.setLayout(mainLayout);
	w.show();
	w.setWindowTitle("running");
	
	return app.exec();
	
}