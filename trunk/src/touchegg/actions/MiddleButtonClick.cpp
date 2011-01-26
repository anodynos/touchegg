/**
 * @file /src/touchegg/actions/MiddleButtonClick.cpp
 *
 * @~spanish
 * Este archivo es parte del proyecto Touchégg, usted puede redistribuirlo y/o
 * modificarlo bajo los téminos de la licencia GNU GPL v3.
 *
 * @~english
 * This file is part of the Touchégg project, you can redistribute it and/or
 * modify it under the terms of the GNU GPL v3.
 *
 * @class  MiddleButtonClick
 * @author José Expósito
 */
#include "MiddleButtonClick.h"

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

MiddleButtonClick::MiddleButtonClick(const QString& settings)
        : Action(settings) {}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

void MiddleButtonClick::executeStart(const QHash<QString, QVariant>&) {}

void MiddleButtonClick::executeFinish(const QHash<QString, QVariant>&) {}

void MiddleButtonClick::executeUpdate(const QHash<QString, QVariant>&) {
    XEvent event;
    memset(&event, 0x00, sizeof(event));
    event.type = ButtonPress;
    event.xbutton.button = Button2;
    event.xbutton.same_screen = true;

    XQueryPointer(QX11Info::display(), QX11Info::appRootWindow(),
        &event.xbutton.root, &event.xbutton.window,
        &event.xbutton.x_root, &event.xbutton.y_root,
        &event.xbutton.x, &event.xbutton.y,
        &event.xbutton.state);

    event.xbutton.subwindow = event.xbutton.window;

    while(event.xbutton.subwindow) {
        event.xbutton.window = event.xbutton.subwindow;
        XQueryPointer(QX11Info::display(), event.xbutton.window,
            &event.xbutton.root, &event.xbutton.subwindow,&event.xbutton.x_root,
            &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y,
            &event.xbutton.state);
    }

    XSendEvent(QX11Info::display(), PointerWindow, True, 0xfff, &event);
    XFlush(QX11Info::display());

    usleep(100000);

    event.type = ButtonRelease;
    event.xbutton.state = 0x100;

    XSendEvent(QX11Info::display(), PointerWindow, True, 0xfff, &event);
    XFlush(QX11Info::display());
}
