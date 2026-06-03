QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        abstractclassunit.cpp \
        abstractfactory.cpp \
        abstractmethodunit.cpp \
        abstractprintoperatorunit.cpp \
        cplusclassunit.cpp \
        cplusfactory.cpp \
        cplusmethodunit.cpp \
        cplusprintoperatorunit.cpp \
        csharpclassunit.cpp \
        csharpfactory.cpp \
        csharpmethodunit.cpp \
        csharpprintoperatorunit.cpp \
        ilog.cpp \
        javaclassunit.cpp \
        javafactory.cpp \
        javamethodunit.cpp \
        javaprintoperatorunit.cpp \
        logtoconsole.cpp \
        main.cpp \
        unit.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstractclassunit.h \
    abstractfactory.h \
    abstractmethodunit.h \
    abstractprintoperatorunit.h \
    cplusclassunit.h \
    cplusfactory.h \
    cplusmethodunit.h \
    cplusprintoperatorunit.h \
    csharpclassunit.h \
    csharpfactory.h \
    csharpmethodunit.h \
    csharpprintoperatorunit.h \
    ilog.h \
    javaclassunit.h \
    javafactory.h \
    javamethodunit.h \
    javaprintoperatorunit.h \
    logtoconsole.h \
    unit.h
