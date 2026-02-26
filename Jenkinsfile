pipeline {
    agent any

    parameters {
        string(name: 'VERSION', defaultValue: 'latest', description: 'Docker image version tag')
    }

    stages {

        stage('Build Backend Image') {
            steps {
                sh '''
                docker build -t backend-image:${VERSION} ./backend
                '''
            }
        }

        stage('Run Backend Containers') {
            steps {
                sh '''
                docker rm -f backend1 backend2 backend3 2>/dev/null || true

                docker run -d --name backend1 backend-image:${VERSION}
                docker run -d --name backend2 backend-image:${VERSION}
                docker run -d --name backend3 backend-image:${VERSION}
                '''
            }
        }

        stage('Build NGINX Image') {
            steps {
                sh '''
                docker build -t custom-nginx:${VERSION} ./nginx
                '''
            }
        }

        stage('Run NGINX') {
            steps {
                sh '''
                docker rm -f nginx 2>/dev/null || true

                docker run -d \
                --name nginx \
                -p 80:80 \
                custom-nginx:${VERSION}
                '''
            }
        }
    }
}
