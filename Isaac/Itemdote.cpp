#include <iostream>
#include <string>
#include <windows.h> 

void TextColor(int font, int backGround)
{
    int Color = font + backGround * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void drawItemPoly()
{
    const int height = 7;
    const int width = 15;

    std::string poly[height] =
    {
        "      0000      ",
        "     011110     ",
        "   0111122110   " ,
        "  011221112210  ",
        " 01111111111110 ",
        "  000222222000  ",
        "     000000     ",
       
      
    };

    for (int i = 0; i < height; ++i)
    {
        std::cout << std::string((120 - width) / 2, ' ');  

        for (char& c : poly[i]) 
        {
            if (c == '0')
            {
                TextColor(0, 0); 
                std::cout << "бс";
            }
            else if (c == '1')
            {
                TextColor(12, 12);
                std::cout << "бс";
            }
            else if (c == '2')
            {
                TextColor(6, 6); 
                std::cout << "бс";
            }
            else
            {
                TextColor(15, 0);
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

   
    TextColor(15, 0); 
}

void drawBandage() 
{
    const int height = 8;
    const int width = 15;

    std::string Bandage[height] = 
    {
        " 11111111111111111  ",
        " 1               1 ",
        " 1       2       1 ",
        " 1      222      1 ",
        " 1       2       1   ",
        " 1               1 ",
        " 11111111111111111 ",
        " ",
                   
     
    };

    for (int i = 0; i < height; ++i) 
    {
        std::cout << std::string((120 - width) / 2, ' '); 

        for (char& c : Bandage[i])
        {
            if (c == '0') 
            {
                TextColor(0, 0); 
                std::cout << "бс";
            }
            else if (c == '1') 
            {
                TextColor(6, 6);  
                std::cout << "бс";
            }
            else if (c == '2')
            {
                TextColor(12, 12);
                std::cout << "бс";
            }
            else if (c == '3')
            {
                TextColor(8, 8);
                std::cout << "бс";
            }
            else
            {
                TextColor(15, 0);
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

   
    TextColor(15, 0); 
}

void DrawRange()
{
    const int height = 11;
    const int width = 8;

    std::string Range[height] = 
    {
        "    0    ",
        "   0 0   ",
        "  0   0  ",
        "  00000  ",
        "    0    ",
        "    0    ",
        "    0    ",
        "    0    ",
        "    0    ",
        "  1 0 1  ",
        " 1  0  1 ",

    };

    for (int i = 0; i < height; ++i)
    {
        std::cout << std::string((120 - width) / 2, ' ');  

        for (char& c : Range[i]) 
        {
            if (c == '0') 
            {
                TextColor(8, 8);  
                std::cout << "бс";
            }
            else if (c == '1') 
            {
                TextColor(15, 15);
                std::cout << "бс";
            }
    
            else 
            {
                TextColor(15, 0); 
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

   
    TextColor(15, 0);  
}

void DrawSpeed()
{
    const int height = 11;
    const int width = 8;

    std::string Speed[height] = 
    {
        " 1111111      0000    ",
        "             0    0   ",
        " 1111111      0000   ",
        "       00000000       ",
        " 1111111     00       ",
        "            00         ",
        "   1111111 00        ",
        "           00000       ",
        "  1111111  0    0      ",
        "       0000      0     ",
        "                 00    ",

    };

    for (int i = 0; i < height; ++i) 
    {
        std::cout << std::string((120 - width) / 2, ' ');  

        for (char& c : Speed[i])
        {
            if (c == '0')
            {
                TextColor(11,11); 
                std::cout << "бс";
            }
            else if (c == '1')
            {
                TextColor(9, 9);  
                std::cout << "бс";
            }

            else 
            {
                TextColor(15, 0); 
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    TextColor(15, 0); 
}
