#include "Core.h"
#include "Label.h"

namespace AL
{
	Label::Label(const std::wstring text, const unsigned int width, const unsigned int height, LABEL_TYPE type, bool isItalic, LABEL_QUALITY quality) :
		_color(Color::White()),
		_text(text),
		_width(width),
		_height(height)
	{
		Init(text, width, height, type, isItalic, quality);
	}

	Label::Label(const std::wstring text, const unsigned int width, const unsigned int height, LABEL_TYPE type, bool isItalic, LABEL_QUALITY quality, const Color color) :
		_color(color),
		_text(text),
		_width(width),
		_height(height)
	{
		Init(text, width, height, type, isItalic, quality, color);
	}

	Label::Label(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const std::wstring fontName) :
		_text(text),
		_width(width),
		_height(height)
	{
		Init(text, width, height, type, isItalic, quality, fontName);
	}

	Label::Label(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const std::wstring fontName, const Color color) :
		_color(color),
		_text(text),
		_width(width),
		_height(height)
	{
		Init(text, width, height, type, isItalic, quality, fontName, color);
	}

	void Label::Init(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality)
	{
		_width = width; 
		_height = height;
		_text = text;
		D3DXCreateFont(DXUTGetD3D9Device(), height, width, static_cast<int>(type), 1, isItalic, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, static_cast<int>(quality), DEFAULT_PITCH | FF_DONTCARE, L"Arial", &_font);
		Renderer::GetInstance()->AddRenderTarget(this);
	}

	void Label::Init(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const Color color)
	{
		_width = width;
		_height = height;
		_text = text;
		_color = color;
		D3DXCreateFont(DXUTGetD3D9Device(), height, width, static_cast<int>(type), 1, isItalic, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, static_cast<int>(quality), DEFAULT_PITCH | FF_DONTCARE, L"Arial", &_font);
		Renderer::GetInstance()->AddRenderTarget(this);
	}

	void Label::Init(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const std::wstring fontName)
	{
		_width = width;
		_height = height;
		_text = text;
		D3DXCreateFont(DXUTGetD3D9Device(), height, width, static_cast<int>(type), 1, isItalic, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, static_cast<int>(quality), DEFAULT_PITCH | FF_DONTCARE, fontName.c_str(), &_font);
		Renderer::GetInstance()->AddRenderTarget(this);
	}

	void Label::Init(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const std::wstring fontName, const Color color)
	{
		_width = width;
		_height = height;
		_text = text;
		_color = color;
		D3DXCreateFont(DXUTGetD3D9Device(), height, width, static_cast<int>(type), 1, isItalic, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, static_cast<int>(quality), DEFAULT_PITCH | FF_DONTCARE, fontName.c_str(), &_font);
		Renderer::GetInstance()->AddRenderTarget(this);
	}

	void Label::Draw()
	{
		RECT rect = { _position.x, _position.y, 0, 0 };
		_font->DrawText(NULL, _text.c_str(), _text.size(), &rect, DT_NOCLIP, _color);
	}
}