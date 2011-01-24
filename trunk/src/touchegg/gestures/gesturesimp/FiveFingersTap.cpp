/**
 * @file /src/touchegg/gestures/gesturesimp/FiveFingersTap.cpp
 *
 * @~spanish
 * Este archivo es parte del proyecto Touchégg, usted puede redistribuirlo y/o
 * modificarlo bajo los téminos de la licencia GNU GPL v3.
 *
 * @~english
 * This file is part of the Touchégg project, you can redistribute it and/or
 * modify it under the terms of the GNU GPL v3.
 *
 * @class  FiveFingersTap
 * @author José Expósito
 */
#include "FiveFingersTap.h"

// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

FiveFingersTap::FiveFingersTap(GeisGestureType type, GeisGestureId id,
        const QHash<QString, QVariant>& attrs, Action* action)
        : Gesture(type, id, attrs, action) {}


// ************************************************************************** //
// **********                    PUBLIC METHODS                    ********** //
// ************************************************************************** //

bool FiveFingersTap::isThisGesture(const QHash<QString, QVariant>& attrs) {
    // "gesture name" = "Tap"
    if(!attrs.contains("gesture name"))
        return false;

    if(attrs.value("gesture name", "") != "Tap")
        return false;

    // touches = 5
    if(!attrs.contains("touches"))
        return false;

    if(attrs.value("touches", -1) != 5)
        return false;


    return true;
}

