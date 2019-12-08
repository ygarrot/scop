#include "scop.h"

char *read_file(char *file_name)
{
	char *buffer;
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (read(fd, buffer, BUFF_SIZE) < 0)
		return (NULL);
	buffer[BUFF_SIZE] = 0;
	return (buffer);
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

void	is_shader_compiled(int shader)
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
	char *vertex_shader_src;
	char *fragment_shader_src;

	vertex_shader_src = read_file("src/shader/vertex_shader");
	fragment_shader_src = read_file("src//shader/fragment_shader");

	if (!vertex_shader_src || !fragment_shader_src)
		return ;
	printf("%s %s\n", fragment_shader_src, vertex_shader_src);
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, (const char*const *)&vertex_shader_src, NULL);
	glCompileShader(vertex_shader);
	is_shader_compiled(vertex_shader);

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, (const char*const *)&fragment_shader_src, NULL);
	glCompileShader(fragment_shader);
	is_shader_compiled(fragment_shader);

	*shader_programme = glCreateProgram();

	glAttachShader(*shader_programme, fragment_shader);
	glAttachShader(*shader_programme, vertex_shader);
	glLinkProgram(*shader_programme);
	glDeleteShader(fragment_shader);
	glDeleteShader(vertex_shader);
}
