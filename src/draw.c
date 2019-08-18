/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:04:29 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/18 14:18:23 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		printf("tesT");
		glfwSetWindowShouldClose(window, true);
	}
}

/* static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) */
/* { */
/* 	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) */
/* 		glfwSetWindowShouldClose(window, GL_TRUE); */
/* } */

static void error_callback(int error, const char *description)
{
	(void)error;
	fputs(description, stderr);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

void	check_link(int shader)
{
	int  success;
	char infoLog[512];

	glGetShaderiv(shader, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		printf("ERROR::SHADER::VERTEX::LINK_FAILED %s\n" ,infoLog);
	}
	else
		printf("SHADER::VERTEX::LINK_DONE\n");
}

void	check_compile(int shader)
{
	int  success;
	char infoLog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED %s\n" ,infoLog);
	}
	else
		printf("SHADER::VERTEX::COMPILATION_DONE\n");
}

void	set_tmp_textures(GLuint *shader_programme)
{
	GLuint vertex_shader;
	GLuint fragment_shader;
	const char *vertex_shader_src =
	"#version 330 core\
		layout (location = 0) in vec3 aPos;\
	layout (location = 1) in vec2 aTexCoord;\
	out vec2 TexCoord;\
\
	uniform mat4 model;\
	uniform mat4 view;\
	uniform mat4 projection;\
\
	void main()\
	{\
		gl_Position =  projection * view * model * vec4(aPos, 1);\
			TexCoord = vec2(aTexCoord.x, aTexCoord.y);\
	}\
	"	;
	const char* fragment_shader_src =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main() {"
		"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
		"}";

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_src, NULL);
	glCompileShader(vertex_shader);
	check_compile(vertex_shader);

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_shader_src, NULL);
	glCompileShader(fragment_shader);
	check_compile(fragment_shader);

	*shader_programme = glCreateProgram();

	glAttachShader(*shader_programme, fragment_shader);
	glAttachShader(*shader_programme, vertex_shader);
	glLinkProgram(*shader_programme);
	glDeleteShader(fragment_shader);
	glDeleteShader(vertex_shader);
}

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

GLFWwindow	*init_window()
{
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "scop", NULL, NULL);
	if (!window)
		return 0;
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		return 0;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	return window;
}

int draw(t_scop *scop)
{
	GLuint shader_programme;
	GLFWwindow* window;

	window = init_window();
	GLuint vao = 0;
	GLuint vbo = 0;
	GLuint ebo = 0;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	list_to_vector_array(scop->position_list, &scop->positions);
	print_vector_array(scop->positions);

	glBufferData(GL_ARRAY_BUFFER,
			scop->positions.size * sizeof(t_vector3),
			scop->positions.content,
			GL_STATIC_DRAW);

	for (size_t i = 0; i < scop->indices.size; i++)
	{
		--((int*)scop->indices.content)[i];
	}
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			scop->indices.size * sizeof(int),
			scop->indices.content,
			GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT,
			GL_TRUE, sizeof(t_vector3), (void*)0);

	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	set_tmp_textures(&shader_programme);
	/* glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); */

	/* print_obj(scop); */

	float i = 0;
	while (1)
	{
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shader_programme);
		glBindVertexArray(vao);

		t_matrix model = identity_matrix(4, 4);
		t_matrix view = identity_matrix(4, 4);
		t_matrix projection = new_matrix(4, 4);
		perspective(90, 3.0/4.0, 0.1, 100, &projection);
		/* set_projection_matrix(&projection, 90, 0.1, 100); */
		/* t_vector3 direction = {0, i, 0}; */

		sleep(1);
		i += 0.1;
		model = matrix4_y_rotate(i);
		/* view = translate(&view, direction); */
		print_matrix(model);
		print_matrix(projection);

		unsigned int model_loc = glGetUniformLocation(shader_programme, "model");
		unsigned int view_loc = glGetUniformLocation(shader_programme, "view");
		unsigned int projection_loc = glGetUniformLocation(shader_programme, "projection");
		glUniformMatrix4fv(model_loc, 1, GL_TRUE, matrix_to_array(model));
		glUniformMatrix4fv(view_loc, 1, GL_TRUE, matrix_to_array(view));
		glUniformMatrix4fv(projection_loc, 1, GL_TRUE, matrix_to_array(projection));

		glDrawElements(GL_TRIANGLES,
				scop->pos_nb, GL_UNSIGNED_INT, 0);
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers(window);
		// update other events like input handling 
		glfwPollEvents();
	}
	glfwDestroyWindow(window);

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	return 1;
}
