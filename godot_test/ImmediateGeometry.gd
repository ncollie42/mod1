extends ImmediateGeometry


var list = []
#list.append(Vector3(-1, 0, 5))

func _ready():
	var noise = OpenSimplexNoise.new()
	noise.period = 80
	noise.octaves = 6
	
	#make starting plane to eddit for heightmap
	var plane_mesh = PlaneMesh.new()
	plane_mesh.size = Vector2(200, 200)
	plane_mesh.subdivide_depth = 200
	plane_mesh.subdivide_width = 200
	
	var t_surface = SurfaceTool.new()
	t_surface.create_from(plane_mesh, 0)
		
	var new_mesh = t_surface.commit()

	var t_mesh_data = MeshDataTool.new()
	t_mesh_data.create_from_surface(new_mesh, 0)
	
	for ii in range (t_mesh_data.get_vertex_count()):
		var vertex = t_mesh_data.get_vertex(ii)
		#change the height of the map at every vertex
		vertex.y = noise.get_noise_3d(vertex.x, vertex.y, vertex.z) * 60
		
		#set vertex back into the tool
		t_mesh_data.set_vertex(ii, vertex)
		list.append(vertex)
		


func _process(_delta):   

	clear()
	
    # Begin draw.
	begin(Mesh.PRIMITIVE_TRIANGLES)
	for n in list:
		add_vertex(n)
	
	end()