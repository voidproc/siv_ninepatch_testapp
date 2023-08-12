# include <Siv3D.hpp> // OpenSiv3D v0.6.11

void Main()
{
	Scene::SetBackground(Color{ U"#f8f8c8" });

	constexpr Size SceneSize{ 160, 144 };
	constexpr int Scale = 4;

	Scene::Resize(SceneSize);
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::Resize(SceneSize * Scale);

	Scene::SetTextureFilter(TextureFilter::Nearest);

	const ScopedRenderStates2D renderState{ SamplerState::ClampNearest };

	FontAsset::Register(U"text", 12, U"k8x12S.ttf", FontStyle::Bitmap);

	NinePatch messageWindowPatch{ U"poke-patch.png", 8 };
	NinePatch leftArrowPatch{ U"left-arrow-patch.png", 8 };

	const Texture siv3dkunTexture{ U"siv3dkun.png" };

	const Texture ballTexture{ U"ball.png" };

	while (System::Update())
	{
		siv3dkunTexture.draw(Arg::topRight = Scene::Rect().tr().moveBy(-20, 12));

		const Rect leftArrowRect{ Scene::Width() / 2, Scene::Height() - 8 * 9, Scene::Width() / 2, 8 * 3 };
		leftArrowPatch.draw(leftArrowRect, 1.0, TextureFilter::Nearest);

		ballTexture.drawAt(leftArrowRect.center());
		ballTexture.drawAt(leftArrowRect.center().movedBy(-20, 0));
		ballTexture.drawAt(leftArrowRect.center().movedBy(-10, 0));
		ballTexture.drawAt(leftArrowRect.center().movedBy(10, 0));
		ballTexture.drawAt(leftArrowRect.center().movedBy(20, 0));

		const Rect messageWindowRect{ 0, Scene::Height() - 8 * 6, Scene::Width(), 8 * 6 };
		messageWindowPatch.draw(messageWindowRect, 1.0, TextureFilter::Nearest);

		constexpr Color TextColor{ U"#405028" };
		FontAsset(U"text")(U"あ！　やせいの　しぶ３Ｄくんが").draw(messageWindowRect.movedBy(8, 8 * 2 - 3), TextColor);
		FontAsset(U"text")(U"とびだしてきた！").draw(messageWindowRect.movedBy(8, 8 * 4 - 3), TextColor);
		FontAsset(U"text")(U"▼").draw(messageWindowRect.br().movedBy(-16, -16 - 3), ColorF{ TextColor, Periodic::Square0_1(1s) });
	}
}
