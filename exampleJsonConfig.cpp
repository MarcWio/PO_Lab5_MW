
#include "json.hpp"
#include <vector>

nlohmann::json getExampleConfig() {
	nlohmann::json config =
	{
		"ARX",
			{
				"A",
					nlohmann::json::array({ 1, -.5, .7 }),
				"B",
					nlohmann::json::array({ .3, .8, 2 }),
				"k",
					{
						1
					},
				"odch_standard",
					{
						0.1
					}
			},
		"Statyczny",
			{
				"MIN",
					{
						-1
					},
				"MAX",
					{
						1
					}
			},
		"PID",
			{
				"k",
					{
						1.1
					},
				"Ti",
					{
						.5
					},
				"Td",
					{
						0
					}
			},
		"Staly",
			{
				"Ograniczony",
				{
					0
				},
				"Start",
				{
					0
				},
				"Koniec",
				{
					100
				},
				"Wartosc",
				{
					0
				}
			},
		"Sinus",
			{
				"Aktywny",
				{
					0
				},
				"Amplituda",
				{
					1.5
				},
				"Czestotliwosc",
				{
					0.4
				}
			},
		"Prostokat",
			{
				"Aktywny",
				{
					0
				},
				"Amplituda",
				{
					2
				},
				"Czestotliwosc",
				{
					0.4
				},
				"Wypelnienie",
				{
					0.4
				}
			},
		"Trojkat",
			{
				"Aktywny",
				{
					0
				},
				"Czestotliwosc",
				{
					0.4
				},
				"Wypelnienie",
				{
					0.4
				}
			},
		"Szum",
			{
				"Aktywny",
				{
					0
				}
			},
		"System",
			{
				"Ilosc",
				{
					200
				}
			}
	};
	return config;
}