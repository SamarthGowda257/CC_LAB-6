pipeline {
    agent any

    stages {

        stage('Build Backend Image') {
            steps {
                sh 'docker build -t backend-image ./backend'
            }
        }

        stage('Run Backend Containers') {
            steps {
                sh '''
                docker run -d --name backend1 backend-image
                docker run -d --name backend2 backend-image
                docker run -d --name backend3 backend-image
                '''
            }
        }

        stage('Build NGINX Image') {
    steps {
        sh 'docker build -t custom-nginx ./nginx'
    }
}
        stage('Run NGINX') {
            steps {
                sh '''
                docker run -d \
                --name nginx \
                -p 80:80 \
                -v $(pwd)/nginx/default.conf:/etc/nginx/conf.d/default.conf \
                nginx
                '''
            }
        }
    }
}
