#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <osgQOpenGL/osgQOpenGLWidget>

class OutputWindow;

namespace Ui {
class MainWindowForm;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_actionExit_triggered();
    void setupOsgView();

protected:
    void create_camera();

private:
    void create_scene();
    void create_timer();
    void create_manipulator();
    Ui::MainWindowForm *mMainWindowUI;
    void timerEvent(QTimerEvent *)override;
    int mTimerId{0};
};

#endif // MAINWINDOW_H
