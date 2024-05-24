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

    QString wtf = QString::fromWCharArray(L"�ɷ��Ϲ���ŷ��i������i�ȹ�i���ݹ�i����iŶ������iŶŶi�Ⱦ͹���iŶ���G����Ŷ�ȹ�����Ŷi����i�����Ŷ����Ŷi����Ŷi����iŶ����Ŷi��");
    QString wtf2 = "GBKLRDJGKLREJGKLJERLKFJLRKEJFGLREJKGFJEKLRJGKLERJGLKRJGLKERJLKGKLENVBFDNVGBKLFDJBNKLRNBLKREKLBJLKRBLKREMBKLNREKLBNKLRENFLKSRFNMKLE";
    QString regularText = QString::fromWCharArray(L" ���˾����������[good]ֱ�ӽ�����趨�������׾���Ĳ�Ҫ̫��Ц[Цcry]����bgm������������˾��ǡ��ţ��֣������ö��ӣ���Ȼ�������Ǽ̳�����[doge]����Ч���������Ǳ�������������ˣ�");
    MultilineLabel label(regularText, 128);
    label.show();

    //TestDialog dlg;
    //dlg.show();

    //CustomIconLabel iconLabel;
    //iconLabel.setIcons(QSize(128, 128), "G:/QT_Dami/qtdemo/res/icons/sphere.png", "G:/QT_Dami/qtdemo/res/icons/more.png");
    //iconLabel.show();

    return app.exec();
}

