#include "FontManager.h"

#include <iostream>

FontManager::FontManager()
{
	fadeTimer = nullptr;
	ResetAlpha();
}

void FontManager::Fade(const vector<Text*>& _texts, const string& _path)
{
	currentAlpha += alphaFactor;

	
	if (alphaFactor > 0 && currentAlpha >= 255)
	{
		fadeTimer->Stop();
		ResetAlpha();
	}
	
	if(alphaFactor < 0 && currentAlpha <= 0)
	{
		for (Text* _text : _texts)
		{
			Load(_text, _path);
		}
		alphaFactor = 1;
		currentAlpha = 0;
	}
	else
	{
		for (Text* _text : _texts)
		{
			Color _color = _text->getFillColor();
			_color.a = currentAlpha;
			_text->setFillColor(_color);
		}
	}
	
}

void FontManager::ResetAlpha()
{
	fadeTimer = nullptr;
	currentAlpha = 255;
	alphaFactor = -1;
}

void FontManager::Load(Text* _text, const string& _path, const bool _isSmooth)
{
	FontData* _fontData = Get(_path);

	if (!_fontData)
	{
		_fontData = new FontData(_path);
		if (!_fontData->loadFromFile(_path))
		{
			cerr << "La police d'écriture n'a pas été correctement chargée !" << endl;
		}

		_fontData->setSmooth(_isSmooth);
	}

	_text->setFont(*_fontData);
}

void FontManager::LoadWithFade(const vector<Text*>& _texts, const string& _path, const float _duration)
{
	if (fadeTimer->IsRunning()) return;

	alphaFactor = -1;

	const function<void()> _callback = [this, _texts, _path]() { Fade(_texts, _path); };
	fadeTimer = new Timer("Font-Fade", _callback, seconds(_duration), true, true);

}
