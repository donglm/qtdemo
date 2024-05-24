#include <QtWidgets>
#include "testdialog.h"
#include "customlabel.h"
#include "multilinelabel.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);


    AppStyle::initStyleSheets(&app);

    //QLabel label("abc");
    //label.setProperty("cssClass", "proppanel");
    //label.show();

    QFont font("Microsoft YaHei", 14);
    app.setFont(font);

    QString wtf = QString::fromWCharArray(L"股份认购热欧冠i建二狗i热狗i俄容共i加热i哦个加热i哦哦i热就过热i哦高颎热累哦热狗加热哦i光荣i额过热哦过热哦i过热哦i过热i哦过热哦i人");
    QString wtf2 = "GBKLRDJGKLREJGKLJERLKFJLRKEJFGLREJKGFJEKLRJGKLERJGLKRJGLKERJLKGKLENVBFDNVGBKLFDJBNKLRNBLKREKLBJLKRBLKREMBKLNREKLBNKLRENFLKSRFNMKLE";
    QString regularText = QString::fromWCharArray(L" 熟人局整活儿就是[good]直接借剧情设定上演认亲局真的不要太搞笑[笑cry]刘（bgm）：啊～这个人就是～张：爸！刘：好儿子，果然这个身高是继承了我[doge]综艺效果这块儿算是被你俩玩儿明白了！");
    MultilineLabel label(regularText, 128);
    label.show();

    //TestDialog dlg;
    //dlg.show();

    //CustomIconLabel iconLabel;
    //iconLabel.setIcons(QSize(128, 128), "G:/QT_Dami/qtdemo/res/icons/sphere.png", "G:/QT_Dami/qtdemo/res/icons/more.png");
    //iconLabel.show();

    return app.exec();
}

