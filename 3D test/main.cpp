//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//# include <windows.h>
//#include <iostream>
//
//#include "Shader.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//
//// ����
//const unsigned int SCR_WIDTH = 1280;
//const unsigned int SCR_HEIGHT = 720;
//
//float factor = 0.2f;
////
////float vertices[] = {
////	//λ��					// ��ɫ					//��������
////	0.5f,	0.5f,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,	1.0f,	//���Ͻ�
////	0.5f,	-0.5f,	0.0f,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,	//���½�
////	-0.5f,	-0.5f,	0.0f,	0.0f,	0.0f,	1.0f,	0.0f,	0.0f,	//���½�
////	-0.5f,	0.5f,	0.0f,	1.0f,	1.0f,	0.0f,	0.0f,	1.0f	//���Ͻ�
////
////};
////
////unsigned int indices[] = {
////	0, 1, 3,		//��һ��������
////	1, 2, 3			//�ڶ���������
////};
//
//float vertices[] = {
//	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
//	0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
//	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
//
//	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
//	-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
//	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//
//	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//
//	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//
//	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
//	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//
//	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
//	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//	-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
//	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
//};
//
//// �ֲ��ռ�-->����ռ�-->�۲�ռ�-->�ü��ռ�-->�ӿڿռ�
//// �Ƚ���ģ�ͣ�ͨ��ģ�;���ʹ��ת�䵽��������ϵ�ϣ�
//// ͨ���۲�����������ռ�תΪ�۲�ռ䣨����ͶӰ����
//// ͨ��ͶӰ����ת��Ϊ�ü��ռ䣨͸��ͶӰ��
//// �ٽ��������ͶӰƽ��ת��ʵ�ʵ��ԣ��������豸��screen�ϣ�Opengl�ڲ�������ɲ��ù��������
//
//int main() {
//	LARGE_INTEGER nFreq;
//	LARGE_INTEGER nBeginTime;
//	LARGE_INTEGER nEndTime;
//	double time;
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	//��ȡ�����������
//	int nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	std::cout << "���֧�ֵ���������Ϊ��" << nrAttributes << std::endl;
//
//	glEnable(GL_DEPTH_TEST);
//
//	//���������ǵ���ɫ��
//	Shader shader("Shader.vs", "Shader.fs");
//
//	//��һ������
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	//unsigned int EBO;
//	//glGenBuffers(1, &EBO);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//����1
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	//����������װ�͹��˵ķ�ʽ
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* data = stbi_load(/*"zhou_yu.bmp"*/"123.png", &width, &height, &nrChannels, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//		std::cout << "�޷��������⣬����������Դ�Ƿ�����" << std::endl;
//	stbi_image_free(data);
//
//	//����2
//	unsigned int texture2;
//	glGenTextures(1, &texture2);
//	glActiveTexture(GL_TEXTURE1);	//��������1����
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	//�����������ƺ͹��˵ķ�ʽ
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//����ͼƬ
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* data2 = stbi_load("123.png", &width, &height, &nrChannels, 0);
//	if (data2) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//		std::cout << "�޷��������⣬����������Դ�Ƿ�����" << std::endl;
//	stbi_image_free(data2);
//
//	//����OpenGL�ĸ������������ĸ�������Ԫ
//	shader.use();
//	shader.setInt("texture1", 0);
//	shader.setInt("texture2", 1);
//
//	//�任
//	//glm::mat4 trans;
//	//trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
//	//trans = glm::rotate(trans, /*glm::radians(90.0f)*/(float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//
//	glm::mat4 view;
//	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));
//
//	glm::mat4 projection;
//	// glm::radians������FOV���Ƕ�Ϊ45�ȡ��ڶ���������������Ļ���߱ȣ�aspect ratio�������ֵ��Ӱ����ʾ�������е�������ԭ����ʾ���Ǳ����졣0.1f�ǽ��ü��棬100.0f��Զ�ü��档
//	projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//
//
//	while (!glfwWindowShouldClose(window)) {
//		QueryPerformanceFrequency(&nFreq);
//		QueryPerformanceCounter(&nBeginTime);
//
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//
//		shader.use();
//
//		glm::mat4 model;
//		// glfwGetTime() ����ת�Ļ�������һ����󲢷ǹ̶�ֵ������ÿһ��ѭ����Ҫ��ʼ��model��Ȼ��ԽתԽ��
//		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//
//		
//		shader.setMat4("model", glm::value_ptr(model));
//		shader.setMat4("view", glm::value_ptr(view));
//		shader.setMat4("projection", glm::value_ptr(projection));
//
//		glBindVertexArray(VAO);	
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//		QueryPerformanceCounter(&nEndTime);
//		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
//		printf("cap thread : %f us \n", time * 1000000);
//
//	}
//
//	glBindVertexArray(0);
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glfwTerminate();
//	return 0;
//}
//
//void processInput(GLFWwindow *window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	//if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//	//	factor += 0.01f;
//	//	if (factor > 1.0f)
//	//		factor = 1.0f;
//	//}
//
//	//if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
//	//	factor -= 0.01f;
//	//	if (factor < 0.0f)
//	//		factor = 0.0f;
//	//}
//
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}