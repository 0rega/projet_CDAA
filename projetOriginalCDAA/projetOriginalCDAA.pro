QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basededonne.cpp \
    contact.cpp \
    fichecontact.cpp \
    gestioncontact.cpp \
    gestioninteraction.cpp \
    gestiontodo.cpp \
    interaction.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    todo.cpp

HEADERS += \
    basededonne.h \
    contact.h \
    fichecontact.h \
    gestioncontact.h \
    gestioninteraction.h \
    gestiontodo.h \
    interaction.h \
    mainwindow.h \
    menu.h \
    todo.h

FORMS += \
    fichecontact.ui \
    mainwindow.ui

TRANSLATIONS += \
    projetOriginalCDAA_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations
QT += sql

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
