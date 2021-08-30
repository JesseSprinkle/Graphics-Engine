# GraphicsRenderer

This is very much a WIP project where I make a graphics engine. This is for fun, but also has been teaching me a lot about graphics engine architecture,
how they function, how to make things efficient, as well as other things. Below is a list of completed things, current tasks, and future goals!

Note: this repo currently won't work without certain dependencies and also might have bugs because I just pushed what I have right now. In the future, I plan to add the dependencies
and only push working code to master so others can see what I've done.

### Done, probably still needs more work but currently functions
1. Window creation, graphics resize when window resizes
2. Classes for shaders, shader programs, meshes, objects, and others (materials exist but need work)
3. A render queue which stores the objects based on the shader it's detected it should use. This is for efficiency.
4. Actually rendering meshes, and in a simple way. All I have to do is pass data to a mesh and make an object using that mesh, and the object appears!

### Current
1. Clean up code and redesign the render process. Currently, I am not using instancing, but if I want to render the same mesh 1000s of times, instancing is hundreds of times
more efficient.
2. Rework materials, separate them from things like position and rotation. I don't particularly like the current design.

### Goals
1. Option to choose shader rather than have it designated. The current designated shader (based on what you based like if it's 3D, 2D etc) will become the default shader
when you make an object so it can be rendered, but it can be replaced (under certain restrictions).
2. Mesh loading from a file. This should be rather easy.
3. Storing object data in a file, so I can reload the objects being rendered dynamically rather than having to recompile if I want to change something.
4. UI, stuff like sliders and dragging object around. This is probably far down the line.
