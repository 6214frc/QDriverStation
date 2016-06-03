/*
 * Copyright (c) 2015-2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _QJOYSTICKS_MAIN_H
#define _QJOYSTICKS_MAIN_H

#include <QObject>
#include <QStringList>
#include <QJoysticks/JoysticksCommon.h>

class SDL_Joysticks;
class VirtualJoystick;

class QJoysticks : public QObject
{
    Q_OBJECT

public:
    static QJoysticks* getInstance();

    Q_INVOKABLE int count() const;
    Q_INVOKABLE int nonBlacklistedCount();
    Q_INVOKABLE int getNumAxes (const int index);
    Q_INVOKABLE int getNumPOVs (const int index);
    Q_INVOKABLE int getNumButtons (const int index);
    Q_INVOKABLE bool isBlacklisted (const int index);
    Q_INVOKABLE bool joystickExists (const int index);

    Q_INVOKABLE QStringList deviceNames() const;
    QList<QJoystickDevice*> inputDevices() const;

    SDL_Joysticks* sdlJoysticks() const;
    VirtualJoystick* virtualJoystick() const;
    QJoystickDevice* getInputDevice (const int index);

public slots:
    void setVirtualJoystickRange (const float range);
    void setVirtualJoystickEnabled (const bool enabled);
    void setBlacklisted (const int index, const bool blacklisted);

protected:
    explicit QJoysticks();

signals:
    void countChanged();
    void POVEvent (const QJoystickPOVEvent& event);
    void axisEvent (const QJoystickAxisEvent& event);
    void buttonEvent (const QJoystickButtonEvent& event);
    void povChanged (const int js, const int pov, const int angle);
    void axisChanged (const int js, const int axis, const double value);
    void buttonChanged (const int js, const int button, const bool pressed);

private slots:
    void resetJoysticks();
    void updateInterfaces();
    void addInputDevice (QJoystickDevice* device);
    void onPOVEvent (const QJoystickPOVEvent& event);
    void onAxisEvent (const QJoystickAxisEvent& event);
    void onButtonEvent (const QJoystickButtonEvent& event);

private:
    SDL_Joysticks* m_sdlJoysticks;
    VirtualJoystick* m_virtualJoystick;

    QList<QJoystickDevice*> m_devices;
};

#endif
