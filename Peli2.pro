TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ai.cpp \
        basicdeck.cpp \
        card.cpp \
        deck.cpp \
        game.cpp \
        graph.cpp \
        main.cpp

HEADERS += \
    ai.h \
    basicdeck.h \
    card.h \
    deck.h \
    game.h \
    graph.h \
    main.h
