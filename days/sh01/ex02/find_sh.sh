find -type f -name '*.sh' -printf '%f\n' | sed -z s/'.sh\n'/'\n'/g
