#ifndef VIEW_HPP
#define VIEW_HPP

#include <QMainWindow>
#include "Facade.hpp"
#include "controller.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Facade &f, QWidget *parent = nullptr);
    ~View();

private:
    Facade &facade;
    Ui::View *ui;
    void on_button_clicked();
    void updateBoard();
private slots:
    void eventHandler(int i, int j);



};

#endif // VIEW_HPP
