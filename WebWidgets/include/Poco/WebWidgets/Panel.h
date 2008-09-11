//
// Panel.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/Panel.h#6 $
//
// Library: WebWidgets
// Package: Views
// Module:  Panel
//
// Definition of the Panel class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef WebWidgets_Panel_INCLUDED
#define WebWidgets_Panel_INCLUDED


#include "Poco/WebWidgets/View.h"


namespace Poco {
namespace WebWidgets {


class WebWidgets_API Panel: public View
	/// A Panel functions as a wrapper around another view and is freely movable/placeable
{
public:
	typedef Poco::AutoPtr<Panel> Ptr;

	Panel();
		/// Creates an unnamed Panel without a child

	Panel(const std::string& name);
		/// Creates the Panel without a child and without a title
		
	Panel(const std::string& name, const std::string& title);
		/// Creates the Panel without a child

	Panel(View::Ptr pChild);
		/// Creates an unnamed Panel with its child

	Panel(const std::string& name, View::Ptr pChild);
		/// Creates the Panel with its child
		
	Panel(const std::string& name, const std::string& title, View::Ptr pChild);
		/// Creates the Panel with its child	

	void setChild(View::Ptr pChild);
		/// Sets the child of the panel

	View::Ptr getChild() const;
		/// Returns the child of the panel

	void setModal(bool val);
		/// Sets modal mode, i.e set to true to mask 
		/// everything behind it when displayed. Default: false

	bool getModal() const;
		/// Returns modal mode

	View::Ptr findChild(const std::string& name) const;
	
	void showCloseIcon(bool val);
		/// Per default the panel has a close icon in the upper right corner.
		/// Set val to false to hide it
		
	bool hasCloseIcon() const;
		/// Returns if the closeicon is shown
		
	void setText(const std::string& text);
		/// Sets the title of this View.
		
	std::string getText() const;
		/// Returns the title of this View.
		
	void setTitle(const std::string& text);
		/// Sets the title of this View.
		
	const std::string& getTitle() const;
		/// Returns the title of this View.	
		
	void showHeader(bool show);
		/// Shows the header of the Panel
		
	bool showHeader() const;
		/// Returns if the header of the Panel is shown
		
	void enable(bool val);
	
	bool enabled() const;
protected:
	~Panel();
		/// Destroys the Panel.

private:
	View::Ptr   _pChild;
	std::string _title;
	bool        _modal;
	bool        _showCloseIcon;
	bool        _showHeader;
	bool        _enabled;
};


//
// inlines
//

inline View::Ptr Panel::getChild() const
{
	return _pChild;
}


inline void Panel::setModal(bool val)
{
	_modal = val;
}


inline bool Panel::getModal() const
{
	return _modal;
}


inline void Panel::showCloseIcon(bool val)
{
	_showCloseIcon = val;
}

		
inline bool Panel::hasCloseIcon() const
{
	return _showCloseIcon;
}


inline void Panel::setText(const std::string& text)
{
	setTitle(text);
}

		
inline std::string Panel::getText() const
{
	return getTitle();
}


inline void Panel::setTitle(const std::string& text)
{
	_title = text;
}

		
inline const std::string& Panel::getTitle() const
{
	return _title;
}


inline void Panel::showHeader(bool show)
{
	_showHeader = show;
}

		
inline bool Panel::showHeader() const
{
	return _showHeader;
}


inline void Panel::enable(bool val)
{
	_enabled = val;
}

	
inline bool Panel::enabled() const
{
	return _enabled;
}


} } // namespace Poco::WebWidgets


#endif // WebWidgets_Panel_INCLUDED
