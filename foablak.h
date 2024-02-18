#ifndef FOABLAK_H
#define FOABLAK_H

#include <QMainWindow>

class FoAblak : public QMainWindow
{
    Q_OBJECT

public:
    FoAblak(QWidget *parent = nullptr);
    ~FoAblak();

private slots:
    void connectSlot();
};
#endif // FOABLAK_H
