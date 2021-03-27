pipeline {
  agent any
  options {
    timestamps();
  }

  stages {
    stage('build in parallel') {
      parallel {
        stage('build suba') {
          build(job: "suba")
        }
        stage('build subb') {
          build(job: "subb")
        }
        stage('build subc') {
          build(job: "subc")
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

