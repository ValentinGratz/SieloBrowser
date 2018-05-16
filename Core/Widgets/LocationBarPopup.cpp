/***********************************************************************************
** MIT License                                                                    **
**                                                                                **
** Copyright (c) 2018 Victor DENIS (victordenis01@gmail.com)                      **
**                                                                                **
** Permission is hereby granted, free of charge, to any person obtaining a copy   **
** of this software and associated documentation files (the "Software"), to deal  **
** in the Software without restriction, including without limitation the rights   **
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      **
** copies of the Software, and to permit persons to whom the Software is          **
** furnished to do so, subject to the following conditions:                       **
**                                                                                **
** The above copyright notice and this permission notice shall be included in all **
** copies or substantial portions of the Software.                                **
**                                                                                **
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     **
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       **
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    **
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         **
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  **
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  **
** SOFTWARE.                                                                      **
***********************************************************************************/

#include "LocationBarPopup.hpp"

#include <QLayout>

namespace Sn {
LocationBarPopup::LocationBarPopup(QWidget* parent) :
	QFrame(parent, Qt::Popup),
	m_alignment(Qt::AlignRight)
{
	setAttribute(Qt::WA_DeleteOnClose);
	setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
	setLineWidth(1);
	setMidLineWidth(2);
}

LocationBarPopup::~LocationBarPopup()
{
	// Empty
}

void LocationBarPopup::showAt(QWidget* parent)
{
	if (!parent || !parent->parentWidget())
		return;

	parent = parent->parentWidget();

	layout()->invalidate();
	layout()->activate();

	QPoint point{parent->mapToGlobal(QPoint(0, 0))};

	if (m_alignment == Qt::AlignRight)
		point.setX(point.x() + parent->width() - width());

	point.setY(point.y() + parent->height());
	move(point);

	QFrame::show();
}

void LocationBarPopup::setPopupAlignment(Qt::Alignment alignment)
{
	m_alignment = alignment;
}

}