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
              target: 'Collected']);
          step ([$class: 'CopyArtifact', 
              projectName: 'subb',
              filter: "sub*.tar.gz",
              target: 'Collected']);
          step ([$class: 'CopyArtifact', 
              projectName: 'subc',
              filter: "sub*.tar.gz",
              target: 'Collected']);
        }
      }
    }
  }
  post {
    always {
      
      archiveArtifacts artifacts: 'Collected/sub*.tar.gz', onlyIfSuccessful: true
      step([$class: 'WsCleanup'])
    }
  }
}

