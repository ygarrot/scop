/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:04:29 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/27 13:56:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/* static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) */
/* { */
/* 	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) */
/* 		glfwSetWindowShouldClose(window, GL_TRUE); */
/* } */
/* static void error_callback(int error, const char* description) */
/* { */
/* 	fputs(description, stderr); */
/* } */
void	set_tmp_textures(GLuint *shader_programme)
{

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main() {"
		"  gl_Position = vec4(vp, 1.0);"
		"}";
	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main() {"
		"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
		"}";
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);
	*shader_programme = glCreateProgram();
	glAttachShader(*shader_programme, fs);
	glAttachShader(*shader_programme, vs);
	glLinkProgram(*shader_programme);

}

GLFWwindow	*init()
{
	GLFWwindow* window;
	/* glfwSetErrorCallback(error_callback); */
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
	if (!window)
		return 0;
	glfwMakeContextCurrent(window);
	glewExperimental=true; // Nécessaire dans le profil de base
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return 0;
	}
	return window;
}

int draw(t_scop *scop)
{
	(void)scop;
	GLFWwindow* window;

	window = init();
	GLuint vao = 0;
	GLuint vbo = 0;
	GLuint ebo = 0;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	list_to_vector_array(scop->position_list, &scop->positions);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,
			scop->positions.size * sizeof(t_vector3),
			scop->positions.content,
			GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			scop->indices.size * sizeof(int),
			scop->indices.content,
			GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT,
			GL_TRUE, sizeof(t_vector3), (void*)0);
	glEnableVertexAttribArray(0);
	/* glVertexAttribPointer(1, 3, GL_FLOAT, */
	/* 		GL_TRUE, sizeof(t_vertex), (void*)sizeof(t_vector3)); */
	/* glEnableVertexAttribArray(1); */
	/* glVertexAttribPointer(2, 3, GL_FLOAT, */
	/* 		GL_TRUE, sizeof(t_vertex), (void*)(2 * sizeof(t_vector3))); */
	/* glEnableVertexAttribArray(2); */
	glBindVertexArray(0);

	GLuint shader_programme;
	set_tmp_textures(&shader_programme);

	while (1)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		// wipe the drawing surface clear
		glBindVertexArray(vao);
		// draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawElements(GL_TRIANGLES,
			   	scop->pos_nb, GL_UNSIGNED_INT, 0);
		// update other events like input handling 
		glfwPollEvents();
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);
	/* glDelete_ve */
	glfwTerminate();
	exit(EXIT_SUCCESS);
	return 1;
}
