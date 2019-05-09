const grpc = require('grpc')
const protoLoader = require('@grpc/proto-loader')

const PROTO_PATH = __dirname + '/../protos/lights.proto'

const packageDefinition = protoLoader.loadSync(PROTO_PATH, {
  keepCase: true,
  longs: String,
  enums: String,
  defaults: true,
  oneofs: true
})

const lightsProto = grpc.loadPackageDefinition(packageDefinition)

;(() => {
  const client = new lightsProto.Lights('localhost:50051', grpc.credentials.createInsecure())
  const call = client.connect()

  call.write({ type: "start_processing" })

  // await new Promise(resolve => setTimeout(resolve, 10000))
  // call.write({ type: "stop_processing" })

  call.on('data', async (detection) => {
    console.log({ detection })
  })
})()