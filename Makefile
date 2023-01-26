# ----------------------------------------------------------------------
#  Development humble
# ----------------------------------------------------------------------

#: Builds a Docker image with the corresponding Dockerfile file
humble.build:
	@docker build -t ros:tam -f docker/humble/Dockerfile .

#: Create Generic Docker container
humble.create: 
	@./docker/run_scripts/run.bash
humble.create.intel: 
	@./docker/run_scripts/runIntelGpu.bash
humble.create.nvidia: 
	@./docker/run_scripts/runNvidiaGpu.bash

#: Start the container in background
humble.up:
	@xhost +
	@docker start ros2-tam

#: Stop the container
humble.down:
	@docker stop ros-tam

#: Restarts the container
humble.restart:
	@docker restart ros-tam

#: Shows the logs of the ros-tam service container
humble.logs:
	@docker logs --tail 50 ros-tam

#: Fires up a bash session inside the ros-tam service container
humble.shell:
	@docker exec -it ros-tam bash

#: Remove ros-tam container. 
humble.remove: humble.down
	@docker container rm ros-tam

# ----------------------------------------------------------------------
#  General Docker Commands
# ----------------------------------------------------------------------

#: Show a list of containers.
list:
	@docker container ls -a

#: Show a list of containers.
listUp:
	@docker ps