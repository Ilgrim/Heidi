/*
 * Copyright 2014 Augustin Cavalier <waddlesplash>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef CORE_CENTRALWINDOW_H
#define CORE_CENTRALWINDOW_H

#include <ObjectList.h>
#include <OutlineListView.h>
#include <Window.h>
#include <FilePanel.h>

#include "HeidiGlobal.h"
#include "Editor.h"
#include "Project.h"

// View Predefinitions
class BTabView;
class BTextView;
class BOutlineListView;
class ToolBarView;
class BGroupLayout;

// Window Predefinitions
class BFilePanel;

// Other Predefinitions
class Project;


class CentralWindow : public BWindow
{
public:
	// 'what' codes that are used internally by this class
	enum WhatCodes {
		CENTRALWINDOW_NEW 	= 'cwNW',
		CENTRALWINDOW_OPEN 	= 'cwOP',
		CENTRALWINDOW_SAVE 	= 'cwSV',
		CENTRALWINDOW_SAVEAS= 'cwSa',
		
		CENTRALWINDOW_ABOUT = 'cwAB'
	};

				CentralWindow(BRect frame);
				~CentralWindow();
	
	Editor*		CurrentEditor();

	void		MessageReceived(BMessage* msg);
	bool		QuitRequested();

	// TODO: Hooks for the projects to call in multiproject mode.
	//status_t	AddProject(Project* project);
	//status_t	RemoveProject(Project* project);

private:
	BGroupLayout*			fRootLayout;
	ToolBarView*			fToolbar;
	
	BOutlineListView*		fProjectTree;
	Project*				fOpenProject;
	
	BTabView*	  			fEditorsTabView;
	BObjectList<Editor>		fOpenEditors;
	
	BFilePanel*				fOpenPanel;
	BTabView*	 	 		fOutputsTabView;
	BTextView*				fBuildIssues;
	BTextView*				fCompileOutput;
	BTextView*				fAppOutput;
};

extern CentralWindow* central_window;

#endif // CORE_CENTRALWINDOW_H
