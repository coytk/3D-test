#include "Shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
	//£¡1¡¢¶ÁÈ¡×ÅÉ«Æ÷µÄ´úÂE
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	//È·±£ÎÄ¼şÁ÷»áÊä³öÒE£
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		//´ò¿ªÎÄ¼ş
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		//¶ÁÈ¡ÎÄ¼şµ½Á÷ÖĞ
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		//¹Ø±ÕÎÄ¼ş
		vShaderFile.close();
		fShaderFile.close();
		//½«Á÷×ª»»Îª×Ö·û´®
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "´úêó£º¶ÁÈ¡ÎÄ¼şÊ§°Ü£¬ÇEEéÎÄ¼şÊÇ·ñ´æÔÚ£¡" << std::endl;
	}

	//£¡2¡¢±àÒEÅÉ«ÆE
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	//¶¥µã×ÅÉ«ÆE
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "±àÒE¥µã×ÅÉ«Æ÷Ê§°Ü£¬´úêóĞÅÏ¢£º" << infoLog << std::endl;
	}

	//Æ¬Ôª×ÅÉ«ÆE
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "±àÒE¬Ôª×ÅÉ«Æ÷Ê§°Ü£¬´úêóĞÅÏ¢£º" << infoLog << std::endl;
	}

	//×ÅÉ«Æ÷³ÌĞE
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "Á¬½Ó×ÅÉ«Æ÷³ÌĞòÊ§°Ü£¬´úêóĞÅÏ¢£º" << infoLog << std::endl;
	}

	//É¾³ı×ÅÉ«Æ÷³ÌĞE
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

///Ê¹ÓÃ×ÅÉ«ÆE
void Shader::use() {
	glUseProgram(ID);
}

/// ÉèÖÃ±äÁ¿Öµ
void Shader::setBool(const std::string& name, bool value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::setInt(const std::string& name, int value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setFloat(const std::string& name, float value) const {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setMat4(const std::string& name, float value[]) const {
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, value);
}