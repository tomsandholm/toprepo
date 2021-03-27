pipeline {
  agent any
  options {
    timestamps();
  }

  stages {
    stage('build in parallel') {
      parallel {
        stage('build suba') {
          steps {
            build(job: "suba")
          }
        }
        stage('build subb') {
          steps {
            build(job: "subb")
          }
        }
        stage('build subc') {
          steps {
            build(job: "subc")
          }
        }
      }
    }
    stage('copy artifacts') {
      steps {
        script {
          step ([$class: 'CopyArtifact', 
              projectName: 'suba',
              filter: "sub*.tar.gz",
              target: 'Infra']);
        }
      }
    }
  }
  post {
    always {
      
      archiveArtifacts artifacts: 'sub*.tar.gz', onlyIfSuccessful: true
      step([$class: 'WsCleanup'])
    }
  }
}
