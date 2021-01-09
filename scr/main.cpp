#include "Renderer.h"
#include <iostream>

int EuclidsAlgorithm(int a, int b);

int GetLCM(int a, int b)
{
	return (a * b)/EuclidsAlgorithm(a,b);
}

int EuclidsAlgorithm(int a, int b)
{
	if (a < 1 || b < 1)return -1;
	int max, min, gcf;
	
	
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}

	while (min > 0)
	{
		gcf = min;
		min = max % min;
		max = gcf;
	}

	return gcf;
}

void Responce(int call, CWindow * window)
{
	switch (call)
	{
	case 1:
	{
		size_t bufflength1 = window->GetTextLengthFromTextBox(2);
		size_t bufflength2 = window->GetTextLengthFromTextBox(3);

		char * buf1 = new char[bufflength1 + 1];
		char * buf2 = new char[bufflength2 + 1];
		memset(buf1, '\0', bufflength1);
		memset(buf1, '\0', bufflength2);

		window->GetTextFromTextBox(2, bufflength1+1, buf1);
		window->GetTextFromTextBox(3, bufflength2+1, buf2);
		int a = atoi(buf1);
		int b = atoi(buf2);

		if (a < 1 || b < 1)
		{
			MessageBox(NULL, "Invalid input!", "ERROR!", MB_OK);
			window->SetTextInTextBox(2, "");
			window->SetTextInTextBox(3, "");
		}
		else
		{
			int gcf = EuclidsAlgorithm(a, b);
			char buffer[12] = "GCF:";
			memset(&buffer[4], '\0', 7);
			_itoa_s(gcf, &buffer[4], 8, 10);
		
			
			MessageBox(NULL, buffer, "Success!", MB_OK);
			window->SetTextInTextBox(2, "");
			window->SetTextInTextBox(3, "");
		}
	}


		break;
	case 2:
	{

		size_t bufflength1 = window->GetTextLengthFromTextBox(2);
		size_t bufflength2 = window->GetTextLengthFromTextBox(3);

		char * buf1 = new char[bufflength1 + 1];
		char * buf2 = new char[bufflength2 + 1];
		memset(buf1, '\0', bufflength1);
		memset(buf1, '\0', bufflength2);

		window->GetTextFromTextBox(2, bufflength1 + 1, buf1);
		window->GetTextFromTextBox(3, bufflength2 + 1, buf2);
		int a = atoi(buf1);
		int b = atoi(buf2);

		if (a < 1 || b < 1)
		{
			MessageBox(NULL, "Invalid input!", "ERROR!", MB_OK);
			window->SetTextInTextBox(2, "");
			window->SetTextInTextBox(3, "");
		}
		else
		{
			int lcm = GetLCM(a,b);
			char buffer[12] = "LCM:";
			memset(&buffer[4], '\0', 7);
			_itoa_s(lcm, &buffer[4], 8, 10);


			MessageBox(NULL, buffer, "Success!", MB_OK);
			window->SetTextInTextBox(2, "");
			window->SetTextInTextBox(3, "");
		}


	}
		break;

	default:
		break;
	}


}



int main()
{
	int w = GetLCM(120, 2420);
	//vec3col(0, 0.5f, 0.2)

	CWindow window(480, 320, "GCF and LCM Calculator - Lloyd Jay Edradan", WINDOW_NO_RESIZE, vec3col(0, 0.5f, 0.2));
	
	window.CreateStaticTextBox(120, 18, 20, 40, "Input Number:");
	window.CreateStaticTextBox(120, 18, 20, 40 + 19, "Input Number:");
	window.CreateInputTextBox(55, 19, 20 + 121, 40, nullptr);
	window.CreateInputTextBox(55, 19, 20 + 121, 40 + 20, nullptr);
	window.CreateButton(80, 40, (480 / 2) - (80 / 2), (320 / 2) + (40 / 2), "GET GCF", 1);
	window.CreateButton(80, 40, (480 / 2) - (80 / 2), (320 / 2) - (40 / 2), "GET LCM", 2);
	window.CreateBitMapImg(120, 120, 480 - 150, 10, "img//SSCTlogo.bmp");

	
	while (!window.WindowShouldClose())
	{
		
		Responce(window.GetButtonMessage(), &window);


		window.SwapWindowBuffers();
		window.ProcessMessageB();
	}


	
	std::cin.get();
	return 0;
}

