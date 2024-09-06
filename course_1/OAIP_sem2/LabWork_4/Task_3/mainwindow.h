#include <QMainWindow>
#include <qgraphicsscene.h>
#include <qspinbox.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    QList<int> getInputValues();
    QList<int> processInput(QList<int> inputValues);
    QList<int> compute(QList<int> input);


private slots:
    void refreshInputTable();
    void refreshOutput();


protected:
    Ui::MainWindow *ui;
};
