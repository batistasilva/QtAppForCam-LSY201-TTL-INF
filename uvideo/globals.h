#ifndef GLOBALS_H
#define GLOBALS_H
#include <QtCore/QtGlobal>

// ALL THE GLOBAL DECLARATIONS

// don't use #include <QString> here, instead do this:

QT_BEGIN_NAMESPACE
class QString;
// class QVector;
class QImage;
QT_END_NAMESPACE

// that way you aren't compiling QString into every header file you put this in...
// aka faster build times.

//#define MAGIC_NUM 42

//extern qreal g_some_double; // Note the important use of extern!
//extern QString g_some_string;
extern QVector<QImage> from_hex_image_list;


class globals
{
public:
    globals();
};

#endif // GLOBALS_H
