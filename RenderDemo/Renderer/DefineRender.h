
enum TextureFormatRender
{
	TEXTURE_FORMAT_RGBA8,
};


struct SwapChainInfo
{
	int FrameBufferCount = 0;
	int Width;
	int height;
	int Hwnd;
	TextureFormatRender Format;

};