#include "Stack.h"
#include <iostream>
#include <cstdio>

std::string openTags[] = { "HTML", "HMTL", "HEAD", "TITLE", "BODY", "H1", "H2","H3","H4","H5","UL", "BR", "TD", "TR", "TABLE", "A", "B", "I", "P",
};

std::string closeTags[] = { "/HTML", "/HMTL", "/HEAD", "/TITLE", "/BODY", "/H1", "/H2","/H3","/H4",
"/H5", "/UL", "/BR", "/TD","/TR", "/TABLE", "/A", "/B", "/I", "/P",
}; 

std::string voidTags[] = { "img", "BR", "LI", "tag"};

int IsClosingTag(std::string tag);
int IsOpeningTag(std::string tag);
int IsVoidTag(std::string tag);



int main(int argc, char** argv) 
{
	// Check amount of parameters *(argc)
	if (argc < 2) {
		std::cout << "Not enough arguments! You called: " << argv[0] << std::endl;
		return EXIT_FAILURE;
	}
	else {
		std::cout << "OK!You called: " << argv[0] << std::endl << argv[1] << std::endl;
		FILE* fp = NULL;

		errno_t erro = fopen_s(&fp, argv[1], "r");

		if (fp == NULL) {
			std::cout << "Error opening file: " << argv[1] << std::endl;
			return EXIT_FAILURE;
		}
		std::string currentTag = "";

		bool readingTag = false;

		Stack<std::string> storedTags;
		Stack<char> storedSymbols;

		char c = ' ';
		bool lastStart = false;
		bool fakeTag = false;
		int index;

		while ((c = std::fgetc(fp)) != EOF) 
		{
			std::cout << c;

			if (c == '>')
			{
				lastStart = false;

				if (fakeTag)
					continue;

				if (storedSymbols.Pop() != '<') {
					std::cout << " Symbol > does not have an opening one ";
					return EXIT_FAILURE;
				}
				readingTag = false;

				if (IsVoidTag(currentTag) != -1)
					continue;

				if (IsClosingTag(currentTag) != -1)
				{
					index = IsClosingTag(currentTag);

					std::string previousTag = storedTags.Pop();

					if (previousTag == openTags[index])
					     continue;
					else
					{
						std::cout << " Tag without a starting one " << currentTag << std::endl;
                        std::cout << " The previous one was " << previousTag << std::endl;
                        return EXIT_FAILURE;
					}
				}
				else if (IsOpeningTag(currentTag) != -1)
				{
					storedTags.Push(currentTag);
					continue;
				}
				else
				{
					std::cout << " Not existing tag " << currentTag;
					return EXIT_FAILURE;
				}
			}
			else if (readingTag == true) 
			{
				if (lastStart && c == ' ')
				{
					fakeTag = true;
				}
				lastStart = false;
				currentTag += c;
			}
            else if (c == '<')
			{
				storedSymbols.Push(c);
				readingTag = true;
				lastStart = true;
				currentTag = "";
			}
		}

		std::cout << std::endl;

		std::fclose(fp);



		return EXIT_SUCCESS;
	}


	return EXIT_SUCCESS;
}

int IsClosingTag(std::string tag) {

	int size = std::size(closeTags);
	for (int i = 0; i < size; i++)
	{
		if (tag.find(closeTags[i]) != std::string::npos)
			return i;
	}

	return -1;
}

int IsOpeningTag(std::string tag) {

	int size = std::size(openTags);
	for (int i = 0; i < size; i++)
	{
		if (tag.find(openTags[i]) != std::string::npos)
			return i;
	}

	return -1;
}

int IsVoidTag(std::string tag) {

	int size = std::size(voidTags);
	for (int i = 0; i < size; i++)
	{
		if (tag.find(voidTags[i]) != std::string::npos)
			return i;
	}

	return -1;
}