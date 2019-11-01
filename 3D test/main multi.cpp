#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "Shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// …Ë÷√
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

float factor = 0.2f;
//
//float vertices[] = {
//	//Œª÷√					// —’…´					//Œ∆¿˙Û¯±ÅE
//	0.5f,	0.5f,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,	1.0f,	//”“…œΩ«
//	0.5f,	-0.5f,	0.0f,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,	//”“œ¬Ω«
//	-0.5f,	-0.5f,	0.0f,	0.0f,	0.0f,	1.0f,	0.0f,	0.0f,	//◊Ûœ¬Ω«
//	-0.5f,	0.5f,	0.0f,	1.0f,	1.0f,	0.0f,	0.0f,	1.0f	//◊Û…œΩ«
//
//};
//
//unsigned int indices[] = {
//	0, 1, 3,		//µ⁄“ª∏ˆ»˝Ω«–Œ
//	1, 2, 3			//µ⁄∂˛∏ˆ»˝Ω«–Œ
//};

float vertices[] = {
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
	-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
};

glm::vec3 cubePositions[] = {
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(2.0f, 5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f, 3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f, 2.0f, -2.5f),
	glm::vec3(1.5f, 0.2f, -1.5f),
	glm::vec3(-1.3f, 1.0f, -1.5f)
};

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//ªÒ»°◊˚–Û Ù–‘ ˝¡ø
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "◊˚–Û÷ß≥÷µƒ Ù–‘ ˝¡øŒ™£∫" << nrAttributes << std::endl;

	glEnable(GL_DEPTH_TEST);

	//£°¥¥Ω®Œ“√«µƒ◊≈…´∆ÅE
	Shader shader("Shader.vs", "Shader.fs");

	//µ⁄“ª∏ˆª∑æ≥
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//unsigned int EBO;
	//glGenBuffers(1, &EBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Œ∆¿ÅE
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	//…Ë÷√Œ∆¿˙ÃÅE∞∫Õπ˝¬Àµƒ∑Ω Ω
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(/*"zhou_yu.bmp"*/"123.png", &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		std::cout << "Œﬁ∑®º”‘ÿŒ Ã‚£¨«ÅEÅEÈ¥˙¬ÅEÚ◊ ‘¥ «∑Ò”–ŒÛ°£" << std::endl;
	stbi_image_free(data);
	
	//Œ∆¿ÅE
	unsigned int texture2;
	glGenTextures(1, &texture2);
	glActiveTexture(GL_TEXTURE1);	//º§ª˚Í∆¿ÅE∂‘œÅE
	glBindTexture(GL_TEXTURE_2D, texture2);
	//…Ë÷√Œ∆¿˙◊∑»∆∫Õπ˝¬Àµƒ∑Ω Ω
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//º”‘ÿÕº∆¨
	//int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data2 = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
	if (data2) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data2);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		std::cout << "Œﬁ∑®º”‘ÿŒ Ã‚£¨«ÅEÅEÈ¥˙¬ÅEÚ◊ ‘¥ «∑Ò”–ŒÛ°£" << std::endl;
	stbi_image_free(data2);
	
	//∏ÊÀﬂOpenGLƒƒ∏ˆ≤…—˘∆˜ Ù”⁄ƒƒ∏ˆŒ∆¿˙—•‘™
	shader.use();
	shader.setInt("texture1", 0);
	shader.setInt("texture2", 1);

	//±‰ªª
	//glm::mat4 trans;
	//trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
	//trans = glm::rotate(trans, /*glm::radians(90.0f)*/(float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 view;
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

	// modify
	// œ»≥ı ºªØ10∏ˆƒ£–Õ£¨≤ª¥Ê‘⁄∏±ƒ£–Õ£®model1£©£¨√ø∏ˆƒ£–Õ∂º «◊‘º∫µƒ÷˜ƒ£–Õ£®modelseq[i]£©
	// √ø¥Œwhile—≠ª∑ƒ⁄µƒfor—≠ª∑∏’ø™ º≥ı ºªØmodel≥…modelseq[i]£¨÷Æ∫Û÷±Ω”rotateæÕ––
	glm::mat4 modelseq[100];
	for (int i = 0; i < 10; ++i) {
		modelseq[i] = glm::translate(modelseq[i], cubePositions[i]);
		float angle = 20.0f * i;
		modelseq[i] = glm::rotate(modelseq[i], glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
	}

	while (!glfwWindowShouldClose(window)) {
		glm::mat4 model;


		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);

		shader.use();
		shader.setMat4("view", glm::value_ptr(view));
		shader.setMat4("projection", glm::value_ptr(projection));

		glBindVertexArray(VAO);
		// œÅE™¥ÅEΩ“ª∂—ŒÅEÂ»∆◊≈“ª∏ˆ∂´Œ˜◊™µƒ–ßπ˚£∫√ø“ª¥Œwhile—≠ª∑∏ƒ±‰“ª¥Œ÷˜ƒ£–Õ£®model£©µƒΩ«∂»£¨√ø¥Œ—≠ª∑ƒ⁄µƒfor—≠ª∑∏’ø™ º ±Ω´∏±ƒ£–Õ£®model1£©≥ı ºªØ≥…÷˜ƒ£–Õ£®model£©
		// ’‚—˘≤Ÿ◊˜÷Æ∫Ûø…“‘∏˘æ›√ø“ª÷°µƒ÷˜ƒ£–Õ£®model£©Œª÷√∫ÕΩ«∂»¿¥…Ë∂®∏±ƒ£–Õ£®model1£©µƒŒª÷√∫ÕΩ«∂»£¨“≤æÕ «Àµ∏±ƒ£–Õ∂º–Ë“™∏˘æ›÷˜ƒ£–Õ¿¥æˆ∂®Œª÷√£¨◊˚Ú’–ßπ˚∏±ƒ£–Õ «»∆◊≈÷˜ƒ£–Õ◊™
		//glm::mat4 model1;
		//model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		//for (int i = 0; i < 10; ++i) {
		//	model1 = model;
		//	model1 = glm::translate(model1, cubePositions[i]);
		//	float angle = 20.0f * i;
		//	model1 = glm::rotate(model1, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		//	shader.setMat4("model", glm::value_ptr(model1));
		//	glDrawArrays(GL_TRIANGLES, 0, 36);
		//}
		
		for (int i = 0; i < 10; ++i) {
			model = modelseq[i];
			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
			shader.setMat4("model", glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	//if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
	//	factor += 0.01f;
	//	if (factor > 1.0f)
	//		factor = 1.0f;
	//}

	//if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
	//	factor -= 0.01f;
	//	if (factor < 0.0f)
	//		factor = 0.0f;
	//}

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
