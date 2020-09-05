# include <Siv3D.hpp>
# include "Title.h"
# include "Game.h"

void Main()
{
	FontAsset::Register(U"TitleFont", 60, Typeface::Heavy);
	App manager;

	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");


	while (System::Update())
	{
		if (!manager.update())
		{
			break;
		}
	}
}

//struct Times
//{
//    float DeltaTime;
//
//    Float3 unused = {};
//};
//
//void Main()
//{
//    const Texture windmill(U"example/windmill.png");
//
//    // R と B を入れ替えるピクセルシェーダ
//    // シェーダファイルの拡張子は、Windows では hlsl, macOS/Linux では frag を選択
//    // {} 内は定数バッファの名前と、対応する定数インデックス
//    const PixelShader ps(U"example/shader/2d/grayscale" SIV3D_SELECT_SHADER(U".hlsl", U".frag"),
//        { { U"PSConstants2D", 0 } });   
//    
//    /*const PixelShader ps_defult(U"example/shader/2d/test" SIV3D_SELECT_SHADER(U".hlsl", U".frag"),
//        { { U"PSConstants2D", 0 }, {U"Times", 1} });*/
//
//    if (!ps)
//    {
//        throw Error(U"Failed to load a shader file");
//    }
//
//    ConstantBuffer<Times> test;
//
//    while (System::Update())
//    {
//        {
//            // R と B を入れ替えるピクセルシェーダを開始
//            ScopedCustomShader2D shader(ps);
//            windmill.draw(10, 10);
//            
//            test->DeltaTime = static_cast<float>(Math::Sin(Scene::Time()));
//            Graphics2D::SetConstantBuffer(ShaderStage::Pixel, 1, test);
//            ScopedCustomShader2D shasder(ps);
//            windmill.draw(10, 200);
//        }
//    }
//}