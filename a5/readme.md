docker build -t fortify-obf .                

docker run --rm -v "$PWD:/output" fortify-obf