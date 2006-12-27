/*
 * Copyright (C) 2004-2006 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __ZLGTKDIALOGMANAGER_H__
#define __ZLGTKDIALOGMANAGER_H__

#include <gtk/gtkwindow.h>
#include <gtk/gtkdialog.h>

#include <ZLDialogManager.h>

class ZLGtkDialogManager : public ZLDialogManager {

public:
	static void createInstance() { ourInstance = new ZLGtkDialogManager(); }

private:
	ZLGtkDialogManager() : myWindow(0), myIsKeyboardGrabbed(false) {}

public:
	void createApplicationWindow(ZLApplication *application) const;

	ZLDialog *createDialog(const std::string &title) const;
	ZLOptionsDialog *createOptionsDialog(const std::string &id, const std::string &title) const;
	void informationBox(const std::string &title, const std::string &message) const;
	void errorBox(const std::string &title, const std::string &message) const;
	int questionBox(const std::string &title, const std::string &message, const std::string &button0, const std::string &button1, const std::string &button2) const;
	bool selectionDialog(const std::string &title, ZLTreeHandler &handler) const;
	void wait(ZLRunnable &runnable, const std::string &message) const;

	void grabKeyboard(bool grab) { myIsKeyboardGrabbed = grab; }
	bool isKeyboardGrabbed() const { return myIsKeyboardGrabbed; }

private:
	int internalBox(const gchar *icon, const std::string &title, const std::string &message, const std::string &button0, const std::string &button1 = "", const std::string &button2 = "") const;

private:
	mutable GtkWindow *myWindow;
	bool myIsKeyboardGrabbed;

friend class ZLGtkOptionsDialog;
friend class ZLGtkSelectionDialog;
friend GtkDialog *createGtkDialog(const std::string& title);
};

#endif /* __ZLGTKDIALOGMANAGER_H__ */
