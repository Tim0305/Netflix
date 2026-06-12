#ifndef GENEROWIDGET_H
#define GENEROWIDGET_H

#include <QWidget>

namespace Ui {
class GeneroWidget;
}

class GeneroWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GeneroWidget(QWidget *parent = nullptr);
    ~GeneroWidget();

private:
    Ui::GeneroWidget *ui;
};

#endif // GENEROWIDGET_H
