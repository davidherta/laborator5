#include "UI.h"

int main()
{
	Movie m1{ string("dwef"), string("qwef"), 1, 2, string("defawf") };
	Movie m2{ string("rjyh"), string("vqrf"), 3, 3, string("zxcv") };
	Movie m3{ string("fowne"), string("g3on"), 12, 3, string("dwea") };
	MovieRepository repo{};
	repo.add(m1);
	repo.add(m2);
	repo.add(m3);
	Watchlist wl{};
	MovieRepository watched{};
	Controller ctrl{ repo, watched, wl };
	UI ui{ ctrl };
	ui.start();
}