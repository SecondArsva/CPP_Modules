#include <iostream>
#include <string>
#include <fstream>

/* It will open the file "filename" and copies its content into a new file
   "filename.replace", replacing every occurrence of s1 with s2. */
int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Error: You must introduce 3 parameters: a filename and two strings, an occurrence and the replace." << std::endl, 1);
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::ifstream	fileFD(filename.c_str());
	std::string		fileContent;
	
	// Comprobación de la existencia del archivo recibido
	if (!fileFD.is_open())
		return (std::cerr << "Error: File does not exist or cannot be opened." << std::endl, 1);

	// Lectura y almacenamiento completo del contenido del archivo
	std::string		bufferLine;
	while (std::getline(fileFD, bufferLine))
			fileContent += bufferLine + "\n";
	fileFD.close();

	// Sustitución de datos que coinciden con s1 por s2
	std::string		finalResult;
	size_t			pos = 0;
	while (pos < fileContent.length())
	{
		size_t found = fileContent.find(s1, pos);
		if (found != std::string::npos)
		{
			// Copy everything before the match
            finalResult.append(fileContent, pos, found - pos);
            // Append the replacement string
            finalResult.append(s2);
            // Move past the replaced string
            pos = found + s1.length();
		}
		else
		{
			// Copy the rest of the content if no more matches
            finalResult.append(fileContent, pos, fileContent.length() - pos);
			break;
		}
	}

	// Creación del archivo de remplazo, verificación de existencia y añadido de datos
	std::string		fileReplacer = filename + ".replace";
	std::ofstream	fileReplacerFD(fileReplacer.c_str());
	if (!fileReplacerFD.is_open())
		return (std::cout << "Error: Cannot create output file." << std::endl, 2);
	fileReplacerFD << finalResult;

	std::cout << "Replacements done. Output saved to: " << fileReplacer << std::endl;
	return (0);
}