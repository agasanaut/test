#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv) {

QApplication app (argc, argv);
QPushButton button;
button.setText("Tejus");
button.setToolTip("A tooltip");
button.show();
return app.exec();
}
