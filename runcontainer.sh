
docker build -t dev .
docker run -d --rm -p 10022:22 -v /Users/dy/gits/cc:/code --name dev dev