/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:04:29 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/08 19:40:43 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		printf("test\n");
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

void setup_vao(GLuint *vao, GLuint *vbo, GLuint *ebo)
{
	glGenVertexArrays(1, vao);
	glBindVertexArray(*vao);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);

	glGenBuffers(1, ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
}

void setup_buffer_data(t_scop *scop)
{
	glBufferData(GL_ARRAY_BUFFER,
			scop->positions.size * sizeof(t_vector3),
			scop->positions.content,
			GL_STATIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			scop->indices.size * sizeof(int),
			scop->indices.content,
			GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT,
			GL_TRUE, sizeof(t_vector3), (void*)0);
}

void register_mvp_matrix(GLuint shader_program, t_matrix model, t_matrix view, t_matrix projection)
{
	unsigned int model_loc = glGetUniformLocation(shader_program, "model");
	unsigned int view_loc = glGetUniformLocation(shader_program, "view");
	unsigned int projection_loc = glGetUniformLocation(shader_program, "projection");
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, matrix_to_array(model));
	glUniformMatrix4fv(view_loc, 1, GL_TRUE, matrix_to_array(view));
	glUniformMatrix4fv(projection_loc, 1, GL_TRUE, matrix_to_array(projection));
}

void move_and_rotate(GLuint shader_program)
{
	static float i = 0;
	t_matrix model = identity_matrix(4, 4);
	t_matrix view = identity_matrix(4, 4);
	t_matrix projection = identity_matrix(4, 4);
	/* perspective(90, 3.0/4.0, 0.1, 100, &projection); */
	/* set_projection_matrix(&projection, 90, 0.1, 100); */
	t_vector3 direction = {0, 0, i};
	(void)direction;

	sleep(1);
	i += 0.1;
	model = matrix_transpose(matrix4_y_rotate(i));
	view = translate(&view, direction);
	/* print_matrix(view); */
	/* print_matrix(model); */
	/* print_matrix(projection); */

	register_mvp_matrix(shader_program, model, view, projection);
}

int draw(t_scop *scop)
{
	GLuint shader_program;
	GLFWwindow* window;
	GLuint vao = 0;
	GLuint vbo = 0;
	GLuint ebo = 0;

	for (size_t i = 0; i < scop->indices.size; i++)
		--((int*)scop->indices.content)[i];
	window = init_window();

	setup_vao(&vao, &vbo, &ebo);
	list_to_vector_array(scop->position_list, &scop->positions);
	setup_buffer_data(scop);
	/* print_vector_array(scop->positions); */

	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	set_tmp_textures(&shader_program);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	/* print_obj(scop); */
	while (1)
	{
		processInput(window);
		/* glClearColor(0.2f, 0.3f, 0.3f, 1.0f); */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shader_program);
		glBindVertexArray(vao);

		move_and_rotate(shader_program);

		glBindVertexArray(vao);
		glDrawElements(
				GL_TRIANGLES,
				scop->pos_nb,
				GL_UNSIGNED_INT,
				0);
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
