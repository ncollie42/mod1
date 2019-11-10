extends Spatial




func _ready():
	var st = SurfaceTool.new()		
	st.begin(Mesh.PRIMITIVE_TRIANGLES)
	
	# Prepare attributes for add_vertex.
	#st.add_normal(Vector3(0, 0, 1))
	#st.add_uv(Vector2(0, 0))
	# Call last for each vertex, adds the above attributes.
	st.add_vertex(Vector3(-5, -1, 0))
	
	#st.add_normal(Vector3(0, 0, 1))
	#st.add_uv(Vector2(0, 0))
	st.add_vertex(Vector3(-5, 1, 0))
	
	#st.add_normal(Vector3(0, 0, 1))
	#st.add_uv(Vector2(0, 0))
	st.add_vertex(Vector3(5, 1, 0))
	
	
	#st.add_normal(Vector3(0, 0, 1))
	#st.add_uv(Vector2(0, 0))

	st.add_vertex(Vector3(5, 0, 0))
	st.add_vertex(Vector3(5, -2, 0))	
	st.add_vertex(Vector3(-5, -2, 0))
		
	st.generate_normals()
	# Create indices, indices are optional.
	st.index()
	
	# Commit to a mesh.
	
	var mesh_instance = MeshInstance.new()
	mesh_instance.mesh = st.commit()
	add_child(mesh_instance)
#func _process(delta):
#	pass
