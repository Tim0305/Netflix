#ifndef GENEROSWINDOW_H
#define GENEROSWINDOW_H

#include <QWidget>

namespace Ui {
class GenerosWindow;
}

class GenerosWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GenerosWindow(QWidget *parent = nullptr);
    ~GenerosWindow();
    void reset();

private:
    Ui::GenerosWindow *ui;
};

#endif // GENEROSWINDOW_H
