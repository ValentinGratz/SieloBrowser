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

#pragma once
#ifndef CORE_CHECKBOXDIALOG_HPP
#define CORE_CHECKBOXDIALOG_HPP

#include "SharedDefines.hpp"

#include <QMessageBox>

#include <QWidget>
#include <QCheckBox>

namespace Sn {

class SIELO_SHAREDLIB CheckBoxDialog: public QMessageBox {
Q_OBJECT
public:
	CheckBoxDialog(const QMessageBox::StandardButtons& buttons, QWidget* parent = nullptr);

	void setCheckBoxText(const QString& text);

	bool isChecked() const;
	void setDefaultCheckState(Qt::CheckState state);

private:
	QCheckBox* m_checkBox{nullptr};
};

}

#endif // CORE_CHECKBOXDIALOG_HPP
