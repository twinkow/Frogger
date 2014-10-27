


int verticeCount = 24;
int faceCount = 12;

float colors[] = 
{
	 0.9f, 0.0f, 0.0f, 1.0f , // 0 - FRONT
	 0.9f, 0.0f, 0.0f, 1.0f , // 1
	 0.9f, 0.0f, 0.0f, 1.0f , // 2	
	 0.9f, 0.0f, 0.0f, 1.0f, // 3

	0.0f, 0.9f, 0.0f, 1.0f , // 1 - RIGHT
	 0.0f, 0.9f, 0.0f, 1.0f , // 5
	 0.0f, 0.9f, 0.0f, 1.0f , // 6	
	 0.0f, 0.9f, 0.0f, 1.0f , // 2

	 0.0f, 0.0f, 0.9f, 1.0f , // 2 - TOP
	 0.0f, 0.0f, 0.9f, 1.0f , // 6
	 0.0f, 0.0f, 0.9f, 1.0f , // 7	
	 0.0f, 0.0f, 0.9f, 1.0f , // 3

	0.0f, 0.9f, 0.9f, 1.0f , // 5 - BACK
	 0.0f, 0.9f, 0.9f, 1.0f , // 4
	 0.0f, 0.9f, 0.9f, 1.0f , // 7	
	 0.0f, 0.9f, 0.9f, 1.0f , // 6

	0.9f, 0.0f, 0.9f, 1.0f , // 4 - LEFT
	 0.9f, 0.0f, 0.9f, 1.0f , // 0
	 0.9f, 0.0f, 0.9f, 1.0f , // 3	
	 0.9f, 0.0f, 0.9f, 1.0f , // 7

	 0.9f, 0.9f, 0.0f, 1.0f , // 0 - BOTTOM
	 0.9f, 0.9f, 0.0f, 1.0f , // 4
	 0.9f, 0.9f, 0.0f, 1.0f , // 5	
	 0.9f, 0.9f, 0.0f, 1.0f  // 1
};

float vertices[] = {
	-0.5f, 0.5f, 0.5f, 1.0f,
	-0.5f, -0.5f, 0.5f, 1.0f,
	0.5f, -0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, -0.5f, 1.0f,
	0.5f, -0.5f, -0.5f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f,
	-0.5f, 0.5f, -0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, -0.5f, 0.5f, 1.0f,
	0.5f, -0.5f, -0.5f, 1.0f,
	0.5f, 0.5f, -0.5f, 1.0f,

	-0.5f, 0.5f, -0.5f, 1.0f,
	-0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, -0.5f, 1.0f,

	-0.5f, 0.5f, -0.5f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f,
	-0.5f, -0.5f, 0.5f, 1.0f,
	-0.5f, 0.5f, 0.5f, 1.0f,

	-0.5f, -0.5f, 0.5f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f,
	0.5f, -0.5f, -0.5f, 1.0f,
	0.5f, -0.5f, 0.5f, 1.0f
};

float normals[] = {
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 

	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, -1.0f,

	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,

	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, -1.0f, 0.0f
};

float texCoords[] = {
	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,

	0.0f, 1.0f,
	0.0f, 0.0f, 
	1.0f, 0.0f,
	1.0f, 1.0f,
};

unsigned int faceIndex[] = {
	0,1,2,0,2,3,
	4,5,6,4,6,7,
	8,9,10,8,10,11,
	12,13,14,12,14,15,
	16,17,18,16,18,19,
	20,21,22,20,22,23
};