extends Spatial

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
		
	#remove the old geometery from the mesh before we add the new vertices	
	for ii in range(new_mesh.get_surface_count()):
		new_mesh.surface_remove(ii)	
	
	#add vertices back into the mesh
	t_mesh_data.commit_to_surface(new_mesh)
	t_surface.begin(Mesh.PRIMITIVE_TRIANGLES)
	t_surface.create_from(new_mesh, 0)
	t_surface.generate_normals()
	
	
	var mesh_instance = MeshInstance.new()
	mesh_instance.mesh = t_surface.commit()
	add_child(mesh_instance)
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	$Rotate.rotate_y(delta * 0.5)
