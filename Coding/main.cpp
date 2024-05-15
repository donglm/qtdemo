#include <QtWidgets>
#include "testdialog.h"
#include "customlabel.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);


    AppStyle::initStyleSheets(&app);

    QLabel label("abc");
    label.setProperty("cssClass", "proppanel");
    label.show();

    //TestDialog dlg;
    //dlg.show();

    //CustomIconLabel iconLabel;
    //iconLabel.setIcons(QSize(128, 128), "G:/QT_Dami/qtdemo/res/icons/sphere.png", "G:/QT_Dami/qtdemo/res/icons/more.png");
    //iconLabel.show();

    return app.exec();
}

